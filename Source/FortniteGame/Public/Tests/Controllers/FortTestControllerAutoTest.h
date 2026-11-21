// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tests/Controllers/FortTestControllerBase.h"
#include "FortTestControllerAutoTest.generated.h"

UENUM()
enum class EFortAutoTestState : uint8
{
	InitialLoad = 0,
	Login = 1,
	FrontendLoad = 2,
	FrontendPvELoad = 3,
	FrontendPvETest = 4,
	PvEMatchmaking = 5,
	ZoneLoad = 6,
	ZoneTest = 7,
	Finished = 8,
	MAX = 9,
};

UCLASS()
class UFortTestControllerAutoTest : public UFortTestControllerBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	EFortAutoTestState CurrentState;

};

