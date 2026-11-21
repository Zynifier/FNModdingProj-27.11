// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "FortSocialListUserEntryBase.generated.h"

class UCommonRichTextBlock;
class UImage;

UCLASS(Abstract)
class UFortSocialListUserEntryBase : public USocialListUserEntryBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialListUserEntryBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_EncourageEpicFriend;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialListUserEntryBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_LastInteraction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialListUserEntryBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_LastInteraction_Hover;

};

