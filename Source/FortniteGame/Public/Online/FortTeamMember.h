// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortTeamMember.generated.h"

class UFortSocialUser;

UCLASS(MinimalAPI)
class UFortTeamMember : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSocialUser> SocialUser;

};

