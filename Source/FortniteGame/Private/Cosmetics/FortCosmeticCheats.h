// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "Player/FortCheatManager.h"
#include "FortCosmeticCheats.generated.h"

class UFortGenericDataStoreManagerComponent;

UCLASS()
class UFortCosmeticCheats : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void BeginCopyEliminationLoadoutRecording();

	UFUNCTION(Exec)
	void CopyLastEliminationLoadout();

	UFUNCTION(Exec)
	void EndCopyEliminationLoadoutRecording();

	UFUNCTION(Exec)
	void SuppressExtantSwap();

private:
	UFUNCTION()
	static void AddStaticHooks();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void AdjustEnlightenedLevel(int32 Delta, int32 Season = -1);

	UFUNCTION()
	UFortGenericDataStoreManagerComponent* GetDataStoreFromOuterController() const;

	UFUNCTION()
	void OnCopyEliminationLoadoutChanged(const TArray<FFortSwapItemAndVariantData>& InLoadout);

	UFUNCTION()
	static void RemoveStaticHooks();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetEnlightenedLevel(int32 Level, int32 Season = -1);

};

