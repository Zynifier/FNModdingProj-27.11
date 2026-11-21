// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/SpecialActor/FortNavigationActor_EventGraphItem.h"
#include "FortNavigationActor_OpenablePresent.generated.h"

class UFortItemDefinition;

UCLASS(Abstract)
class AFortNavigationActor_OpenablePresent : public AFortNavigationActor_EventGraphItem
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnOpenPresent(bool bActionCancelled);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetPresent();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShakePresent(const UFortItemDefinition* ItemDef);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePackageRotation(float XRotationValue, float YRotationValue);

private:
	UPROPERTY(EditDefaultsOnly, Category="Scene Nav")
	float TurnSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Scene Nav")
	float OpenDelay;

	UPROPERTY(EditDefaultsOnly, Category="Scene Nav")
	FVector StartingOrigin;

	UPROPERTY(Transient)
	bool bCanInspect;

};

