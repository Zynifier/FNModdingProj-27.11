// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "StateTreeTaskBase.h"
#include "LWMEncounterStartStateTreeTask.generated.h"

class AActor;
class UFortAthenaLivingWorldEncounter;
class ULWMEncounterInstance;

USTRUCT(meta=(Category="Encounter", DisplayName="LWM Encounter [Start]"))
struct FLWMEncounterStartStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FLWMEncounterStartStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bUseEncounterTagQuery;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="bUseEncounterTagQuery", Optional))
	FGameplayTagQuery LWMEncounterTagQuery;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="!bUseEncounterTagQuery", Optional))
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> LWMEncounter;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery PointProviderTagQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bUseVolumeAsAnchor;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(EditCondition="!bUseVolumeAsAnchor", Optional))
	FGameplayTagQuery AnchorPointTagQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FScalableFloat LeashRadiusInner;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FScalableFloat LeashRadiusOuter;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer EncounterIdentifierTags;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<ULWMEncounterInstance> EncounterInstance;

};

