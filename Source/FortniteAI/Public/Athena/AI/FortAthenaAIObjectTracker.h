// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortAthenaAIObjectTracker.generated.h"

class AActor;
class AFortPlayspace;
class UObject;

UENUM(BlueprintType)
enum class EFortAthenaAIObjectTrackerQueryOrder : uint8
{
	// Picks the first valid one

	None = 0,
	// Picks the closest one to the AI (from StartLocation to the object's location)

	Distance = 1,
};

USTRUCT()
struct FAITrackedObjectsSet
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortAthenaAIObjectTrackerQuerySimplified
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaAIObjectTrackerQuerySimplified")
	EFortAthenaAIObjectTrackerQueryOrder PickOrder;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaAIObjectTrackerQuerySimplified")
	bool bMustBeUsable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaAIObjectTrackerQuerySimplified")
	FGameplayTagQuery RequiredTagsQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaAIObjectTrackerQuerySimplified")
	FVector MaximumDistance;

	UPROPERTY(BlueprintReadWrite, Category="FortAthenaAIObjectTrackerQuerySimplified")
	TObjectPtr<AFortPlayspace> RequiredToBeInPlayspace;

};

USTRUCT(BlueprintType)
struct FFortAthenaAIObjectTrackerQuery : public FFortAthenaAIObjectTrackerQuerySimplified
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAthenaAIObjectTrackerQuery")
	FVector StartLocation;

};

UCLASS()
class FORTNITEAI_API UFortAthenaAIObjectTracker : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AI", meta=(DisplayName="Make Full Athena AI Object Tracker Query from a Simplified Query.", NativeMakeFunc))
	static FFortAthenaAIObjectTrackerQuery BP_MakeFullAthenaAIObjectTrackerQueryFromSimplified(const FFortAthenaAIObjectTrackerQuerySimplified& SimplifiedQuery, const AActor* OptionalQuerier);

private:
	UPROPERTY(Transient)
	TMap<TSubclassOf<UObject>, FAITrackedObjectsSet> TrackedObjects;

};

