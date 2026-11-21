// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "FortSidebarTagsNoFriendsEntry.generated.h"

UCLASS()
class UFortSidebarTagsNoFriendsEntry : public USocialListEntryBase
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void OpenFindFriendsPanel() const;

};

