import requests
from bs4 import BeautifulSoup
import csv
from datetime import datetime
import time
import os

class BBCNewsScraper:
    def __init__(self):
        self.headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
        }
        self.base_url = "https://www.bbc.com"
        self.categories = {
            'news': '/news',
            'sport': '/sport',
            'business': '/business',
            'innovation': '/innovation', 
            'culture': '/culture',
            'arts': '/arts',
            'travel': '/travel',
            'earth': '/earth'
        }
        # 初始化CSV文件名
        self.csv_filename = f'bbc_all_news_{datetime.now().strftime("%Y%m%d_%H%M%S")}.csv'
        self.headers_written = False

    def extract_card_data(self, card):
        """Extract data from a single news card"""
        try:
            link_element = card.select_one('a[data-testid="internal-link"]')
            link = self.base_url + link_element['href'] if link_element else ""
            
            img = card.select_one('img.efFcac')
            img_url = img['src'] if img else ""
            img_alt = img['alt'] if img else ""
            
            headline = card.select_one('[data-testid="card-headline"]')
            title = headline.text.strip() if headline else ""
            
            description = card.select_one('[data-testid="card-description"]')
            desc_text = description.text.strip() if description else ""
            
            timestamp = card.select_one('[data-testid="card-metadata-lastupdated"]')
            time_text = timestamp.text.strip() if timestamp else ""
            
            category = card.select_one('[data-testid="card-metadata-tag"]')
            category_text = category.text.strip() if category else ""
            
            is_video = bool(card.select_one('svg[icon="play"]'))
            content_type = "video" if is_video else "article"

            return {
                'title': title,
                'description': desc_text,
                'link': link,
                'image_url': img_url,
                'image_alt': img_alt,
                'timestamp': time_text,
                'category': category_text,
                'type': content_type
            }
            
        except Exception as e:
            print(f"Error extracting card data: {e}")
            return None

    def write_to_csv(self, articles, main_category):
        """Write articles to CSV file"""
        headers = ['title', 'description', 'link', 'image_url', 
                    'image_alt', 'timestamp', 'category', 'type', 'main_category']
        
        try:
            mode = 'w' if not self.headers_written else 'a'
            with open(self.csv_filename, mode, newline='', encoding='utf-8-sig') as f:
                writer = csv.DictWriter(f, fieldnames=headers)
                if not self.headers_written:
                    writer.writeheader()
                    self.headers_written = True
                
                for article in articles:
                    if article:
                        article['main_category'] = main_category
                        writer.writerow(article)
                        
            print(f"Added {len(articles)} articles from {main_category}")
        except Exception as e:
            print(f"Error writing to CSV: {e}")

    def scrape_category(self, category, url_path):
        """Scrape news from a specific category"""
        full_url = self.base_url + url_path
        print(f"\nScraping {category} from {full_url}")
        
        try:
            response = requests.get(full_url, headers=self.headers)
            if response.status_code == 200:
                soup = BeautifulSoup(response.text, 'html.parser')
                cards = soup.select('[data-testid="edinburgh-card"]')
                print(f"Found {len(cards)} news cards in {category}")
                
                category_articles = []
                for idx, card in enumerate(cards, 1):
                    article_data = self.extract_card_data(card)
                    if article_data:
                        category_articles.append(article_data)
                        print(f"Processed {idx}/{len(cards)}: {article_data['title'][:50]}...")
                
                return category_articles
            else:
                print(f"Failed to fetch {category} page: Status code {response.status_code}")
                return []
                
        except Exception as e:
            print(f"Error scraping {category}: {e}")
            return []

    def scrape_all_categories(self):
        """Scrape news from all categories"""
        total_articles = 0
        all_articles = {}
        
        for category, url_path in self.categories.items():
            print(f"\n{'='*50}")
            print(f"Processing category: {category}")
            print(f"{'='*50}")
            
            articles = self.scrape_category(category, url_path)
            if articles:
                all_articles[category] = articles
                total_articles += len(articles)
                self.write_to_csv(articles, category)
            
            time.sleep(2)
        
        print(f"\nTotal articles saved to {self.csv_filename}: {total_articles}")
        return all_articles

def main():
    scraper = BBCNewsScraper()
    print("Starting BBC News scraper...")
    all_articles = scraper.scrape_all_categories()
    
    print("\nScraping Summary:")
    print("="*30)
    for category, articles in all_articles.items():
        print(f"{category}: {len(articles)} articles")
    print("="*30)

if __name__ == "__main__":
    main()