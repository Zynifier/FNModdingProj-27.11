// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/Systems/AthenaAIService.h"
#include "AthenaAIServiceGroup.generated.h"

class UFortPawnComponent_AIGroup;

USTRUCT()
struct FORTNITEAI_API FAthenaAIServiceGroupInfo
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	int32 GroupID;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPawnComponent_AIGroup> GroupLeader;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortPawnComponent_AIGroup>> GroupMembers;

	UPROPERTY(Transient)
	FGameplayTagContainer GroupTags;

};

UCLASS()
class FORTNITEAI_API UAthenaAIServiceGroup : public UAthenaAIService
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	int32 GroupIndexCount;

	UPROPERTY(Transient)
	TArray<FAthenaAIServiceGroupInfo> GroupList;

};

