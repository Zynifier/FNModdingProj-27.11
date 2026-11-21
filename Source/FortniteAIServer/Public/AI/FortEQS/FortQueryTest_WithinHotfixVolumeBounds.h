// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Math/MathFwd.h"
#include "FortQueryTest_WithinHotfixVolumeBounds.generated.h"

class UDataTable;

UCLASS()
class UFortQueryTest_WithinHotfixVolumeBounds : public UEnvQueryTest
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_WithinHotfixVolumeBounds", meta=(RowType="/Script/Engine.HotfixVolumePlacement"))
	TObjectPtr<UDataTable> BoundsTable;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_WithinHotfixVolumeBounds")
	FVector BoundsExtentBuffer;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_WithinHotfixVolumeBounds")
	bool bXYOnly;

};

