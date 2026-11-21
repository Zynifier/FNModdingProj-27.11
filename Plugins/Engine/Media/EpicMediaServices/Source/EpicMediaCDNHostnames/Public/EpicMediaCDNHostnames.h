// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EpicMediaCDNHostnames.generated.h"

UCLASS(BlueprintType, Blueprintable)
class EPICMEDIACDNHOSTNAMES_API UEpicMediaCDNHostnames : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MediaHostnames")
	TArray<FString> GetHostnames();

	UFUNCTION(BlueprintCallable, Category="MediaHostnames")
	FString GetSelectedHostName();

	UPROPERTY(BlueprintReadWrite, Category="MediaHostnames")
	TArray<float> CDNDistribution;

};

