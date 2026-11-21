// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "ValkyriePerProjectUserConfig.generated.h"

UCLASS(Config=EditorPerProjectUserSettings)
class VALKYRIEEDITOR_API UValkyriePerProjectUserConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	FString ProjectName;

	UPROPERTY(Config)
	FString LastMap;

	UPROPERTY(Config)
	FString LastBuildCommitMessage;

	UPROPERTY(Config)
	FString SourceControlProviderName;

	UPROPERTY(Config)
	TMap<FString, FString> SourceControlProviderParameters;

	UPROPERTY(Config)
	FDateTime LastOpenedTime;

	UPROPERTY(Config)
	bool bIsArchived;

};

