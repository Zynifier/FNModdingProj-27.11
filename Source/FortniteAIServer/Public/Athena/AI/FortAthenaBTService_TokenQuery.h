// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "GameplayTagContainer.h"
#include "FortAthenaBTService_TokenQuery.generated.h"

USTRUCT()
struct FEquippedItemTagAssociationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EquippedItemTagAssociationData")
	FGameplayTagQuery ItemTagQuery;

	UPROPERTY(EditAnywhere, Category="EquippedItemTagAssociationData")
	FGameplayTagQuery TokenSystemTagQuery;

};

UCLASS(BlueprintType, Blueprintable)
class FORTNITEAISERVER_API UFortAthenaBTService_TokenQuery : public UBTService
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaBTService_TokenQuery")
	TArray<FEquippedItemTagAssociationData> EquippedItemTagAssociationDatas;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName WeaponKeyName;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Blackboard", meta=(AllowPrivateAccess="true"))
	FName TargetActorName;

};

