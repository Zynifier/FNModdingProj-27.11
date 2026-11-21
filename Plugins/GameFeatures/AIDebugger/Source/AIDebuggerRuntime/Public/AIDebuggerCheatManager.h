// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "AIDebuggerCheatManager.generated.h"

UCLASS()
class UAIDebuggerCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void EnableNavMeshVisualizer(const bool bEnable);

	UFUNCTION(Exec)
	void NextNavMesh();

	UFUNCTION(Exec)
	void StartAIDebugger(const FString AIDebuggerSoftClassPath = TEXT(""));

};

