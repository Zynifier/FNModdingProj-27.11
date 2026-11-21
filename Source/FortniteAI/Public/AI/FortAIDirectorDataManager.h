// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "GameFramework/Actor.h"
#include "FortCombatTypes.h"
#include "FortAIDirectorDataManager.generated.h"

class UObject;
enum class EFortAIDirectorFactor : uint8;

UENUM()
enum class EFortAIDirectorEventContribution : uint8
{
	Increment = 0,
	Set = 1,
};

UENUM(meta=(ScriptName="FortAIDirectorFactorContributionType"))
namespace EFortAIDirectorFactorContribution
{
	enum Type
	{
		Direct = 0,
		Inverse = 1,
	};
}

USTRUCT(BlueprintType)
struct FAIDirectorEventData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FAIDirectorEventData")
	EFortAIDirectorEvent Event;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FAIDirectorEventData")
	FCurveTableRowHandle DataMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FAIDirectorEventData")
	FCurveTableRowHandle CoolDownRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FAIDirectorEventData")
	EFortAIDirectorEventContribution ContributionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FAIDirectorEventData")
	EFortAIDirectorEventParticipant OwnerParticipantType;

};

USTRUCT(BlueprintType)
struct FFortAIDirectorFactorContribution
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AIDirectorEvent")
	EFortAIDirectorEvent AIDirectorEvent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Multiplier")
	float MaxContribution;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ContributionType")
	TEnumAsByte<EFortAIDirectorFactorContribution::Type> ContributionType;

};

USTRUCT(BlueprintType)
struct FFortAIDirectorFactorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FCombatFactorData")
	EFortAIDirectorFactor AIDirectorFactor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FCombatFactorData")
	TArray<FFortAIDirectorFactorContribution> ContributingEvents;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FCombatFactorData")
	float MaxValue;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation"))
class AFortAIDirectorDataManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AIDirectorFactors")
	float GetAIDirectorFactorValue(EFortAIDirectorFactor AIDirectorFactor) const;

	UFUNCTION()
	virtual void TriggerEvent(const FFortAIDirectorEvent& TriggeredEvent);

protected:
	UPROPERTY()
	TObjectPtr<UObject> OwnerObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AIDirectorEvents")
	TArray<FAIDirectorEventData> EventsToTrack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AIDirectorFactors")
	TArray<FFortAIDirectorFactorData> FactorsToTrack;

	UPROPERTY(Transient)
	TArray<EFortAIDirectorFactor> FactorsBeingTracked;

};

