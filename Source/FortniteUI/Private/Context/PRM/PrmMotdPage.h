// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Context/PRM/PrmPageBase.h"
#include "PrmMotdPage.generated.h"

UENUM()
enum class EResponseActions : uint8
{
	Seen = 0,
	LeftFrontend = 1,
	LogOut = 2,
	Refreshed = 3,
	ContentCleared = 4,
};

UCLASS()
class UPrmMotdPage : public UPrmPageBase
{
	GENERATED_BODY()

};

