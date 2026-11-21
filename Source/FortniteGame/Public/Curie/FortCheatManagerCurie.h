// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortCheatManagerCurie.generated.h"

UCLASS()
class UFortCheatManagerCurie : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ApplyCurieElementToBuildingsNearCursor(const FString ElementTag, const float Magnitude, const int32 MaxActors, const int32 MaxSearchCells = 100) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ApplyCurieElementToCursor(const FString ElementTag, const float Magnitude) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ApplyCurieElementToSelf(const FString ElementTag, const float Magnitude) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DisableCurieElementAttachmentUnderCursor(const FString ElementTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DisableCurieElementInteractionUnderCursor(const FString ElementTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DisableCurieStateAttachmentUnderCursor(const FString StateTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableCurieElementAttachmentUnderCursor(const FString ElementTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableCurieElementInteractionUnderCursor(const FString ElementTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void EnableCurieStateAttachmentUnderCursor(const FString StateTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieBuildingGridDebug(const int32 MinOccupiedGridCellsWarning = 100) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieDebugForSelf() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieDebugUnderCursor() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieElementSpatialGridDebug() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieGrassGridDebug() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieManagerDebug() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintCurieSpatialManagerDebug() const;

	UFUNCTION(Exec)
	void PrintCurieVFXManagerDebug(const bool bVerbose) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintFirePropagationDebugUnderCursor() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void PrintFirePropagationManagerDebug() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetBaseFirePropagationRate(const float NewRate) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetDefaultConnectivityPointsForFirePropagation(const int32 NewDefaultConnectivityPoints) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetDefaultFirePropagationFuel(const int32 NewPropagationFuel) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetFireBoundsExpansionValue(const float X, const float Y, const float Z) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetFirePropagationApplicationMagnitude(const float NewMagnitude) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetFirePropagationApplicationMagnitudeRandomizationRange(const float Min, const float Max) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetFirePropagationHalfAngleForUpwardMobilityCalculation(const float NewHalfAngle) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetFirePropagationManagerTickInterval(const float NewTickInterval) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetOverlapFireApplicationMagnitude(const float NewMagnitude) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void VisLogAllElementSubGridNodes(const FString ElementTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void VislogElementSubgridCollision(const FString ElementTag) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void VislogWaterBodyOctree() const;

};

