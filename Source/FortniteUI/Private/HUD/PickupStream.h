// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "PickupStream.generated.h"

class UFortWorldItem;
class UTexture2D;
class UUserWidget;
class UVerticalBox;

USTRUCT()
struct FPickupStreamEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> PickupWidget;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UPickupStream : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleItemPickedUp(UFortWorldItem* WorldItem, int32 Count);

	UFUNCTION(BlueprintImplementableEvent)
	void RefreshPickupEntry(UUserWidget* EntryWidget, const TSoftObjectPtr<UTexture2D>& Icon, int32 Count);

	UPROPERTY(Transient)
	TArray<FPickupStreamEntry> PickupDisplayEntries;

	UPROPERTY(EditDefaultsOnly, Category="PickupStream")
	int32 MaxDisplayedItems;

	UPROPERTY(EditDefaultsOnly, Category="PickupStream")
	TSubclassOf<UUserWidget> PickupEntryWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="PickupStream")
	float ExpirationTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="PickupStream", meta=(AllowPrivateAccess="TRUE", BindWidget, BlueprintProtected="TRUE", EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_PickupMessages;

};

