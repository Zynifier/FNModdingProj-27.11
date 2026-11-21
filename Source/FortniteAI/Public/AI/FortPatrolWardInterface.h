// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPatrolWardInterface.generated.h"

enum class EWardAffectType : uint8;

UENUM(BlueprintType)
enum class EWardAffectType : uint8
{
	AffectsBothStartAndEndPoints = 0,
	AffectsOnlyStartPoints = 1,
	AffectsOnlyEndPoints = 2,
};

UINTERFACE(BlueprintType)
class UFortPatrolWardInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortPatrolWardInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="PatrolWard")
	float GetAffectingDistance() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="PatrolWard")
	EWardAffectType GetAffectingType() const;

};

