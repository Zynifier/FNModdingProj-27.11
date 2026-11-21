// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "AthenaReplayBrowserRowProxyInstance.generated.h"

USTRUCT(BlueprintType)
struct FAthenaReplayBrowserRowData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData")
	FString Name;

	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData")
	FDateTime Date;

	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData", meta=(ClampMin="0.000000"))
	float Length;

	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData", meta=(ClampMin="1"))
	int32 Rank;

	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData", meta=(ClampMin="1"))
	int32 NumPlayers;

	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData", meta=(ClampMin="0"))
	int32 Eliminations;

	UPROPERTY(EditAnywhere, Category="AthenaReplayBrowserRowData", meta=(ClampMin="0"))
	int32 DownloadModulesCount;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Saved"))
	bool bDesignTime_Saved;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Old"))
	bool bDesignTime_Old;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Corrupt"))
	bool bDesignTime_Corrupt;
#endif

};

UCLASS()
class UAthenaReplayBrowserRowProxyInstance : public UObject
{
	GENERATED_BODY()

};

