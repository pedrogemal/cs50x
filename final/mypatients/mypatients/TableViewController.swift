//  Created by Pedro Lanzieri on 13/11/20.
//

import UIKit

class TableViewController: UITableViewController {
    
    var topics = [Topic]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        fetchContents()

    }
    
    func fetchContents() {
        do {
            
            let data = try Data(contentsOf: Bundle.main.url(forResource: "Datamin", withExtension: "json")!)
            let decoded = try JSONDecoder().decode([Topic].self, from: data)
            self.topics = decoded
               
        }
        
        catch {
            
            print(error)
            
        }
        
        loadContents()
    }
    
    func loadContents() {
        
        DispatchQueue.main.async {
           self.tableView.reloadData()
        }
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return topics.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "ListCell", for: indexPath)
        cell.textLabel?.text = topics[indexPath.row].title
        return cell
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "ShowDetailSegue",
                let destination = segue.destination as? DetailViewController,
                let index = tableView.indexPathForSelectedRow?.row {
            destination.information = topics[index].text
        }
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return "General information"
    }
    
    
}



