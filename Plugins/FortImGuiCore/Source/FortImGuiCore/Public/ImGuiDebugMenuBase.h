// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ImGuiDebugMenuBase.generated.h"

class APlayerController;

UCLASS()
class FORTIMGUICORE_API AImGuiDebugMenuBase : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void ToggleInputLock();

private:
	UPROPERTY()
	APlayerController* PrivateLocalPlayerController;

};

