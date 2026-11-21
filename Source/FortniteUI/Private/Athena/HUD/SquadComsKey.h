// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "SquadComsKey.generated.h"

class AActor;
class AFortPawn;
class AFortPlayerController;
enum class EUnconvertReason : uint8;

UCLASS()
class USquadComsKey : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleBindNPCConvertEvent(AFortPlayerController* PlayerController, AActor* OldViewTarget, AActor* NewViewTarget);

	UFUNCTION()
	void HandleOnNPCConvertEvent(AFortPawn* ConvertedFortPawn);

	UFUNCTION()
	void HandleOnNPCUnconvertEvent(AFortPawn* UnconvertedFortPawn, const EUnconvertReason UnconvertReason);

};

