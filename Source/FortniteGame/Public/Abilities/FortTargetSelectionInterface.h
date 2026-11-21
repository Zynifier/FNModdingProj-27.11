// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortTargetSelectionInterface.generated.h"

class UFortGameplayAbility;
enum class EFortAbilityTargetingSource : uint8;

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortTargetSelectionInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortTargetSelectionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability")
	virtual FTransform GetTargetingTransform(EFortAbilityTargetingSource Source, UFortGameplayAbility* SourceAbility = nullptr) const;

};

