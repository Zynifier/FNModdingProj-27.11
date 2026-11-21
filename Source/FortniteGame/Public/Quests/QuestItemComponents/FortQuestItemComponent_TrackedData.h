// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestItemComponents/FortQuestItemComponent.h"
#include "FortQuestItemComponent_TrackedData.generated.h"

USTRUCT()
struct FMutableFortTrackedDataType
{
	GENERATED_BODY()

};

USTRUCT()
struct FMutableFortTrackedDataWrapper
{
	GENERATED_BODY()

};

USTRUCT()
struct FMutableFortTrackedData_GUID : public FMutableFortTrackedDataType
{
	GENERATED_BODY()

};

USTRUCT()
struct FMutableFortTrackedData_Tags : public FMutableFortTrackedDataType
{
	GENERATED_BODY()

};

USTRUCT()
struct FMutableObjectiveExtension_TrackedData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TMap<FName, FMutableFortTrackedDataWrapper> SubjectToTrackedDataMapping;

};

UCLASS()
class UFortQuestItemComponent_TrackedData : public UFortQuestItemComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<FName, FMutableObjectiveExtension_TrackedData> ObjectivesExtensionDataMutable;

};

