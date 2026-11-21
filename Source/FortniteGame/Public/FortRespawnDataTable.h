// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "FortRespawnDataTable.generated.h"

class UDataTable;

USTRUCT()
struct FFortRespawnDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRespawnDataRow")
	FLinearColor FadeColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRespawnDataRow")
	float FadeOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRespawnDataRow")
	float FadeInTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRespawnDataRow")
	float WaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRespawnDataRow")
	float SafetyTime;

};

UCLASS()
class UFortRespawnDataTable : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRespawnDataTable")
	TObjectPtr<UDataTable> RespawnData;

};

