// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Math/MathFwd.h"
#include "Athena/Vehicle/FortTowhookModel.h"
#include "FortPhysicsTowHook.generated.h"

class AActor;
enum class FTowhookExtensionState : uint8;

UCLASS(Config=Game)
class AFortPhysicsTowHook : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_ReplicatedAttachStates();

private:
	UFUNCTION(BlueprintPure)
	bool GetEndPoint(FVector& OutEndPoint) const;

	UFUNCTION(BlueprintPure)
	bool GetStartPoint(FVector& OutStartPoint) const;

	UFUNCTION(BlueprintCallable)
	void SetTowhookExtensionState(FTowhookExtensionState NewExtensionState);

	UPROPERTY(ReplicatedUsing=OnRep_ReplicatedAttachStates)
	TArray<FNetTowhookAttachState> ReplicatedAttachStates;

	UPROPERTY(Transient)
	TObjectPtr<AActor> AlwaysAttachedActor;

};

