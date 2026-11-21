// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserTreeView.h"
#include "FortGiftingSocialUserListView.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortGiftingSocialUserListView : public USocialUserListViewBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditInstanceOnly, Category="FortGiftingSocialUserListView")
	float RefreshRecipientStatusDelay;

};

