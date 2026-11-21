// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "TasksOverFramesScheduleManager.generated.h"

UENUM()
enum class ETasksOverFramesSchedulePriorityCategory : uint8
{
	Default = 0,
	CharacterCustomization = 1,
};

UCLASS()
class UTasksOverFramesScheduleManager : public UWorldSubsystem
{
	GENERATED_BODY()

};

