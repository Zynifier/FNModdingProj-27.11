// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortEncounterEnvironmentQueryInfo.h"
#include "FortEncounterSettings.h"
#include "Missions/MissionSaving/MissionSavingTypes.h"
#include "FortAIEncounterSequence.generated.h"

class AActor;
class AFortAIDirector;
class AFortMission;
class UFortAIAssignmentSettings;
class UFortAIEncounterInfo;
enum class EFortEncounterSequenceResult : uint8;

UENUM(BlueprintType)
enum class EFortEncounterSequenceResult : uint8
{
	Success = 0,
	FailedEncounterInProgress = 1,
	Failed = 2,
};

UCLASS(BlueprintType)
class UFortAIEncounterSequence : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIEncounter")
	bool EncounterBelongsToSequence(UFortAIEncounterInfo* InEncounter) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIEncounter")
	UFortAIEncounterInfo* GetCurrentEncounter() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIEncounter")
	int32 GetEncounterIndexInSequence() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIEncounter")
	int32 GetNumEncountersInSequence() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIEncounter")
	bool HasEncounter() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="AIEncounter")
	bool IsOnFinalIndexInSequence() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	EFortEncounterSequenceResult Last();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	EFortEncounterSequenceResult Next();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	EFortEncounterSequenceResult Previous();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	void SetEncounterStartingData(const TArray<AActor*>& InTargetActors, UFortAIAssignmentSettings* InAssignmentSettings, FEncounterEnvironmentQueryInfo InOverrideEnvironmentQueryInfo, AActor* InOptionalQueryActor, FGameplayTagContainer InInjectedTags, FFortEncounterSettings InEncounterSettings);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	UFortAIEncounterInfo* StartCurrentEncounter(EFortEncounterSequenceResult& OutRequestResult, const TArray<AActor*>& InTargetActors, UFortAIAssignmentSettings* InAssignmentSettings, FEncounterEnvironmentQueryInfo InOverrideEnvironmentQueryInfo, AActor* InOptionalQueryActor, FGameplayTagContainer InInjectedTags, FFortEncounterSettings InEncounterSettings, int32 ActivationDelay = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	UFortAIEncounterInfo* StartCurrentEncounterWithSavedData(EFortEncounterSequenceResult& OutRequestResult, int32 ActivationDelay = 0);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AIEncounter")
	void StopCurrentEncounter();

protected:
	UPROPERTY()
	FFortGeneratedEncounterSequence GeneratedEncounterSequence;

	UPROPERTY()
	int32 CurrentEncounterIndexInSequence;

	UPROPERTY()
	TObjectPtr<UFortAIEncounterInfo> CurrentEncounter;

	UPROPERTY()
	TObjectPtr<AFortAIDirector> AssociatedAIDirector;

	UPROPERTY()
	TObjectPtr<AFortMission> AssociatedMission;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> TargetActors;

	UPROPERTY()
	TObjectPtr<UFortAIAssignmentSettings> AssignmentSettings;

	UPROPERTY()
	FEncounterEnvironmentQueryInfo OverrideEnvironmentQueryInfo;

	UPROPERTY()
	TObjectPtr<AActor> OptionalQueryActor;

	UPROPERTY()
	FGameplayTagContainer InjectedTags;

	UPROPERTY()
	FFortEncounterSettings EncounterSettings;

};

