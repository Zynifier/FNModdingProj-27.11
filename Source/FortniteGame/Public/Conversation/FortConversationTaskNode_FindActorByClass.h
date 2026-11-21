// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Conversation/FortConversationTaskNode_Service.h"
#include "FortConversationTaskNode_FindActorByClass.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FFindActorByClassData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	TSubclassOf<UObject> ClassFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FGameplayTagQuery TargetFilter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FScalableFloat MaxToFind;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FScalableFloat MaxRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FScalableFloat ShowToSquad;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FScalableFloat ShowMarkerDetails;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FScalableFloat Price;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FindActorByClassData")
	FScalableFloat Rarity;

};

UCLASS(Abstract, BlueprintType)
class UFortConversationTaskNode_FindActorByClass : public UFortConversationTaskNode_Service
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Find Actor By Class")
	TArray<FFindActorByClassData> FilterDatas;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Analytics")
	FGameplayTag AnalyticsTag;

};

