// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AI/FortAIEncounterInfoOwnerInterface.h"
#include "FortAIGoalProvider.generated.h"

class UFortAIAssignment;
class UFortAIEncounterInfo;
class UWorld;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAIGoalProvider : public UObject, public IFortAIEncounterInfoOwnerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Encounter")
	virtual UFortAIEncounterInfo* GetEncounterInfo() const;

	UFUNCTION(BlueprintCallable, Category="AIGoalProvider")
	virtual bool InitializeGoalProvider(UWorld* ContextWorld, UFortAIAssignment* Assignment);

	UFUNCTION(BlueprintCallable, Category="AIGoalProvider")
	virtual void UpdateGoals();

private:
	UPROPERTY(Transient)
	TObjectPtr<UWorld> World;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIAssignment> AssignmentOwner;

	UPROPERTY(Transient)
	TObjectPtr<UFortAIEncounterInfo> EncounterInfo;

};

