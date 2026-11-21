// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortHomebaseNodeItemUtilities.generated.h"

class AFortPlayerController;
class UFortHomebaseNodeItem;
enum class EFortHomebaseSquadType : uint8;

UCLASS()
class UFortHomebaseNodeItemUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static bool AreAnyHomebaseNodeItemsUnseenForSquadId(AFortPlayerController* FortPC, const FName& SquadId);

	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static bool AreAnyHomebaseNodeItemsUnseenForSquadType(AFortPlayerController* FortPC, const EFortHomebaseSquadType SquadType);

	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static UFortHomebaseNodeItem* GetHomebaseNodeItemForSquadSlot(AFortPlayerController* FortPC, const FName& SquadId, const int32 SquadSlot);

	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static UFortHomebaseNodeItem* GetHomebaseNodeItemForTagContainer(AFortPlayerController* FortPC, const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static FString GetHomebaseNodeItemNameForTagContainer(AFortPlayerController* FortPC, const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static bool IsHomebaseNodeItemUnseenForTagContainer(AFortPlayerController* FortPC, const FGameplayTagContainer& Tags);

	UFUNCTION(BlueprintCallable, Category="HomebaseNodeItem")
	static bool IsSquadSlotUnseen(AFortPlayerController* FortPC, const FName& SquadId, const int32 SquadSlot);

};

