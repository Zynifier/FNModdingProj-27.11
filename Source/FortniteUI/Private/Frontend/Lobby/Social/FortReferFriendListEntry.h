// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReleaseVersion.h"
#include "SocialUserListEntry.h"
#include "FortReferFriendListEntry.generated.h"

UCLASS(Abstract)
class UFortReferFriendListEntry : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

};

