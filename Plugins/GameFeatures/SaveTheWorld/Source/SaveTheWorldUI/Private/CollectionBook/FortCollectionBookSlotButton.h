// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortCollectionBookSlotButton.generated.h"

class UFortCollectionBookSlotWidget;
class UMenuAnchor;
class UUserWidget;
enum class EFortCollectionBookPopupButtonType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCollectionBookButtonItemUpdatedDelegate);

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCollectionBookSlotButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void PopupMenuClosedWithAction(EFortCollectionBookPopupButtonType Selection);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCollectionBookSlotButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookSlotWidget> CollectionBookSlotWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCollectionBookSlotButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> PopupMenuAnchor;

private:
	UFUNCTION()
	UUserWidget* GetPopupMenu();

	UFUNCTION()
	void OnSlottedItemUpdated();

};

