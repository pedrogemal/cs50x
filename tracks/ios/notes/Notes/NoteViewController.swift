import UIKit

class NoteViewController: UIViewController {
    @IBOutlet var contentTextView: UITextView!
    @IBOutlet var deleteButton: UIButton!
    
    var note: Note? = nil
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        contentTextView.text = note!.content
    }
    
    override func viewWillDisappear(_ animated: Bool) {
        super.viewWillDisappear(animated)
        
        note!.content = contentTextView.text
        NoteManager.shared.saveNote(note: note!)
    }
    
    @IBAction func deleteNote() {
        
        let refreshAlert = UIAlertController(title: "Delete", message: "This note will be lost.", preferredStyle: UIAlertController.Style.alert)

        refreshAlert.addAction(UIAlertAction(title: "Ok", style: .default, handler: { (action: UIAlertAction!) in
            NoteManager.shared.deleteNote(note: self.note!)
            self.navigationController?.popViewController(animated: true)
        }))

        refreshAlert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: { (action: UIAlertAction!) in
              print("Handle Cancel Logic here")
        }))

        present(refreshAlert, animated: true, completion: nil)
        
    }
    
    
}
