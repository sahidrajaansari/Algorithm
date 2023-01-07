import tkinter as tk

class AddressConverter:
    def __init__(self, root):
        # Create a TLB with some initial entries
        self.tlb = {0: 0x1000, 1: 0x2000, 2: 0x3000}

        # Create a label and entry for the logical address
        self.logical_address_label = tk.Label(root, text="Logical Address:")
        self.logical_address_entry = tk.Entry(root)

        # Create a button to perform the conversion
        self.convert_button = tk.Button(root, text="Convert", command=self.convert)

        # Create a label to display the result
        self.result_label = tk.Label(root)

        # Place the widgets in the root window
        self.logical_address_label.pack()
        self.logical_address_entry.pack()
        self.convert_button.pack()
        self.result_label.pack()

    def convert(self):
        # Get the logical address from the entry
        logical_address = int(self.logical_address_entry.get())

        # Look up the corresponding physical address in the TLB
        physical_address = self.tlb.get(logical_address, -1)

        if physical_address == -1:
            # If the address is not in the TLB, display an error message
            self.result_label.config(text="Address not found in TLB")
        else:
            # Otherwise, display the physical address
            self.result_label.config(text=f"Physical Address: {physical_address:x}")

if __name__ == "__main__":
    root = tk.Tk()
    converter = AddressConverter(root)
    root.mainloop()
