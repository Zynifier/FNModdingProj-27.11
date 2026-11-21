// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortLocalTeam.generated.h"

class UFortTeamMember;

UCLASS(Abstract, MinimalAPI)
class UFortLocalTeam : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<UFortTeamMember>> TeamMembers;

};

UCLASS(MinimalAPI)
class UFortAthenaTeam : public UFortLocalTeam
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UFortCampaignTeam : public UFortLocalTeam
{
	GENERATED_BODY()

};

