// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionListEntry.h"
#include "FortSidebarCollectionListEntryEditTags.generated.h"

class UImage;
enum class ESocialTagCategory : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortSidebarCollectionListEntryEditTags : public UAthenaCollectionListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Get Is SocialTag Checked")
	const bool GetIsCheckmarkVisible() const;

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Collection List Item checkmark visibiliy did change"))
	void BP_OnCollectionListItemCheckmarkChanged(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Collection List Item Set"))
	void BP_OnCollectionListItemSet(const FText& TagName, const ESocialTagCategory& TagCategory);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarCollectionListEntryEditTags", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CheckMark;

};

