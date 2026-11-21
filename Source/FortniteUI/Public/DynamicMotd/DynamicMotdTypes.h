// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicMotdTypes.generated.h"

class UMotdActionBase;

UENUM(BlueprintType)
enum class EMotdButtonStyle : uint8
{
	Main = 0,
	Secondary = 1,
};

USTRUCT(BlueprintType)
struct FMotdImage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MotdImage")
	FString Url;

	UPROPERTY(BlueprintReadOnly, Category="MotdImage")
	int32 Width;

	UPROPERTY(BlueprintReadOnly, Category="MotdImage")
	int32 Height;

};

USTRUCT(BlueprintType)
struct FMotdBackground
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MotdBackground")
	TArray<FMotdImage> Images;

};

USTRUCT(BlueprintType)
struct FMotdButton
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MotdButton")
	FText Text;

	UPROPERTY(BlueprintReadOnly, Category="MotdButton")
	EMotdButtonStyle Style;

	UPROPERTY(BlueprintReadOnly, Transient, Category="MotdButton")
	TObjectPtr<UMotdActionBase> Action;

};

USTRUCT(BlueprintType)
struct FMotdVideo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MotdVideo")
	FString UID;

	UPROPERTY(BlueprintReadOnly, Category="MotdVideo")
	FString VideoString;

	UPROPERTY(BlueprintReadOnly, Category="MotdVideo")
	bool bAutoplay;

	UPROPERTY(BlueprintReadOnly, Category="MotdVideo")
	bool bStreamingEnabled;

};

