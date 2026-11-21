// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/AIComponent.h"
#include "VPingComponent.generated.h"

class AFortPawn;
class UFortPawnComponent_AIBotPingCommand;
enum class EUnconvertReason : uint8;

UCLASS(ClassGroup=("Fortnite"))
class COMPANIONAI_API UPingComponentBase : public UAIComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UFortPawnComponent_AIBotPingCommand* CachedAIBotPingCommand;

private:
	UFUNCTION()
	void HandleOnNPCConvertedEvent(AFortPawn* InstigatorPawn, AFortPawn* ConvertedPawn);

	UFUNCTION()
	void HandleOnNPCUnconvertedEvent(AFortPawn* UnconvertedFortPawn, EUnconvertReason UnconvertReason);

};

