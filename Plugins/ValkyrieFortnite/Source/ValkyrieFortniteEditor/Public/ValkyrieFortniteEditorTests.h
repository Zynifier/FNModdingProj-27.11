// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Tests/FortProfileUtils.h"
#include "ValkyrieFortniteEditorTests.generated.h"

USTRUCT()
struct FValkyrieTestProject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString FriendlyName;

	UPROPERTY()
	FString Path;

	UPROPERTY()
	bool bShouldRunInCIS;

};

UCLASS(Config=Game)
class UValkyrieEditorTestProfile : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TArray<FValkyrieTestProject> ProjectPathsToTest;

	UPROPERTY(Config)
	TArray<FProfileGoCommand> CommandsToRun;

};

