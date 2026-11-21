// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "GameplayStreamingClassLoader.generated.h"

/**
 * Class that contains a FSoftClassPath for the GameplayStreamingService class to use for the project
 * as well as the FSoftClassPaths for the classes of the different handlers that will be used for each streaming platforms
 */
UCLASS(Config=GameplayStreaming)
class UGameplayStreamingClassLoader : public UObject
{
	GENERATED_BODY()

private:
	/** Sets the GameplayStreamingService class, which can be overridden via config file to support game-specific gameplay streaming logic. */
	UPROPERTY(Config)
	FSoftClassPath GameplayStreamingServiceClassName;

};

