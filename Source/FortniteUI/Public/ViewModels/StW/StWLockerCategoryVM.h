// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/Athena/AthenaLockerCategoryVM.h"
#include "StWLockerCategoryVM.generated.h"

class UFortMcpProfileCampaign;

UCLASS()
class UStWBackblingLockerCategoryConfig : public UAthenaLockerCategoryConfig
{
	GENERATED_BODY()

};

UCLASS()
class UStWHeroLockerCategoryConfig : public UAthenaLockerCategoryConfig
{
	GENERATED_BODY()

};

UCLASS()
class UStWLockerCategoryVM : public UAthenaLockerCategoryVM
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleDifferentHeroLoadoutActivated(const UFortMcpProfileCampaign* Profile);

};

