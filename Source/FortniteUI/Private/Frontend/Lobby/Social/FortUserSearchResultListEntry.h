// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortPresenceUserListEntry.h"
#include "FortUserSearchResultListEntry.generated.h"

class UCommonRichTextBlock;

UCLASS(meta=(DisableNativeTick))
class UFortUserSearchResultListEntry : public UFortPresenceUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetNamePlatformAndMutuals(const FText& DisplayName, const FText& Platform, int32 MutualCount);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUserSearchResultListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_NameMatchesAndMutuals;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUserSearchResultListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_MutualFriends;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortUserSearchResultListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_MutualFriends_Hover;

};

