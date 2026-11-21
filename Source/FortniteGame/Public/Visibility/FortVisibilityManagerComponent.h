// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortVisibilityManagerComponent.generated.h"

class AActor;
class UFortVisibilityComponent;

USTRUCT()
struct FVisibilityInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> Actor;

	UPROPERTY(NotReplicated, Export, meta=(EditInline="true"))
	UFortVisibilityComponent* VisibilityComponent;

	UPROPERTY()
	uint16 TeamVisibilityFlag;

};

USTRUCT()
struct FVisibiltyInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FVisibilityInfo> VisibilityInfoArray;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"))
class UFortVisibilityManagerComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortVisibilityManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Replicated)
	FVisibiltyInfoArray VisibilityInfoArray;

private:
	UPROPERTY(EditAnywhere, Category="FortVisibilityManagerComponent")
	bool bPlayersAlwaysVisible;

};

