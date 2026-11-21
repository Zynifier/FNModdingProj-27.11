// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineToxicityServiceMcp.generated.h"

USTRUCT()
struct FJsonToxicityBulkEvaluationRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> names;

};

USTRUCT()
struct FJsonToxicityBulkEvaluationRequestLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> texts;

};

USTRUCT()
struct FJsonToxicityBulkEvaluationResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<bool> isToxic;

};

USTRUCT()
struct FJsonToxicityEvaluationRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString name;

};

USTRUCT()
struct FJsonToxicityEvaluationRequestLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString text;

};

USTRUCT()
struct FJsonToxicityEvaluationResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool toxic;

};

