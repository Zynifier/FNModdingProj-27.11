// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaLockerItemInfo.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortItemDefinition;
enum class EAthenaLockerInfoRestrictionWarning : uint8;

UENUM(BlueprintType)
enum class EAthenaLockerInfoRestrictionWarning : uint8
{
	UnsatisfiedExclusiveItem = 0,
	LockedEmote = 1,
	CosmeticRestriction = 2,
	AllItemsAreArchived = 3,
	Unknown = 4,
};

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaLockerItemInfo : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetItemDefinition(const UFortItemDefinition* ItemDefinition, FText ItemDefinitionTitleOverride = FText::GetEmpty());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemDefinitionSet(const UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNoItemSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Exclusive Item")
	void OnUpdateAccessRestrictionWarning(bool bShouldShow, const FText& WarningText, EAthenaLockerInfoRestrictionWarning WarningType);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLockerItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemType;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLockerItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemRarity;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLockerItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaLockerItemInfo", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

};

