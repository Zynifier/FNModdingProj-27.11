// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "CommonPopupMenuLegacy.generated.h"

class UMenuAnchor;
class UObject;

UCLASS()
class COMMONUILEGACY_API UCommonPopupMenuLegacy : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Common Popup Menu")
	void SetContextProvider(const UObject* ContextProvidingObject);

	// End UCommonActivatablePanelLegacy

	UFUNCTION(BlueprintCallable, Category="Common Popup Menu")
	void SetOwningMenuAnchor(const UMenuAnchor* MenuAnchor);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="Common Popup Menu")
	void HandlePostDifferentContextProviderSet();

	UFUNCTION(BlueprintNativeEvent, Category="Common Popup Menu")
	void HandlePreDifferentContextProviderSet();

	UFUNCTION()
	void OnIsOpenChanged(bool IsOpen);

	UFUNCTION(BlueprintCallable, Category="Common Popup Menu")
	void RequestClose();

	/** Used to push the menu onto the input stack. 
	  *	NOTE: Do not change this unless you are aware of the consequences for not using the input stack!
	  */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Common Popup Menu")
	bool bUseInputStack;

	UPROPERTY(BlueprintReadOnly, Export, Category="Common Popup Menu", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UMenuAnchor> OwningMenuAnchor;

	UPROPERTY(BlueprintReadOnly, Category="Common Popup Menu", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UObject> ContextProvidingObject;

};

