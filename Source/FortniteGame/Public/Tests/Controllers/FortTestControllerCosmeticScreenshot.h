// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Tests/Controllers/FortTestControllerBase.h"
#include "FortTestControllerCosmeticScreenshot.generated.h"

class AActor;
class UAthenaCosmeticItemDefinition;

USTRUCT()
struct FCosmeticScreenshotChannelArray
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Channels;

};

USTRUCT()
struct FScreenshotTransformPair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FTransform Left;

	UPROPERTY()
	FTransform Right;

};

USTRUCT()
struct FCosmeticScreenshotTestConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ScreenshotResX;

	UPROPERTY()
	int32 ScreenshotResY;

	UPROPERTY()
	TSet<FString> CosmeticIgnores;

	UPROPERTY()
	TSet<FString> VariantIgnores;

	UPROPERTY()
	TSet<FString> CosmeticWhitelist;

	UPROPERTY()
	TMap<FString, FScreenshotTransformPair> IndividualOverrides;

	UPROPERTY()
	TMap<FString, FCosmeticScreenshotChannelArray> VariantChannelIgnores;

};

UCLASS()
class UFortTestControllerCosmeticScreenshot : public UFortTestControllerBase
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TSet<TObjectPtr<UAthenaCosmeticItemDefinition>> LoadedCosmetics;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> SpawnedActors;

	UPROPERTY()
	TArray<TSubclassOf<AActor>> WrappableActors;

};

