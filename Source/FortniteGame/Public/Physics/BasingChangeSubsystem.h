// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "BasingChangeSubsystem.generated.h"

class AActor;
class AFortPawn;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FBasingChangeDelegate, AFortPawn*, BasedPawn);

UCLASS(MinimalAPI)
class UBasingChangeSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Basing Change Subsystem")
	void RegisterActorForBaseChangeNotify(AActor* ActorToRegister, FBasingChangeDelegate InBasingChangeDelegate);

	UFUNCTION(BlueprintCallable, Category="Basing Change Subsystem")
	void UnregisterActorFromBaseChangeNotify(AActor* ActorToUnregister);

};

