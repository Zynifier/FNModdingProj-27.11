// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ObjectTracking/FortBudgetCategory.h"
#include "FortMetricInformation.generated.h"

USTRUCT(BlueprintType)
struct FMetricStateInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MetricStateInformation")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category="MetricStateInformation")
	FString Description;

	UPROPERTY(BlueprintReadOnly, Category="MetricStateInformation")
	EFortBudgetCategory Category;

	UPROPERTY(BlueprintReadOnly, Category="MetricStateInformation")
	int32 Cost;

	UPROPERTY(BlueprintReadOnly, Category="MetricStateInformation")
	int32 Budget;

};

USTRUCT(BlueprintType)
struct FDetailedMetricInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DetailedMetricInformation")
	TArray<FMetricStateInformation> MetricStates;

};

USTRUCT(BlueprintType)
struct FSimpleMetricInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	TArray<EFortBudgetCategory> CategoryNames;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	TArray<int32> CategoryValues;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	TArray<int32> CategoryBudgets;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	FVector Location;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	float NormalizedGroupBudgetValue;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	int32 GroupTotalBudget;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	FVector NeighbourGroupCenter;

	UPROPERTY(BlueprintReadOnly, Category="SimpleMetricInformation")
	TArray<uint8> NeighbourGroupBudgetValue;

};

