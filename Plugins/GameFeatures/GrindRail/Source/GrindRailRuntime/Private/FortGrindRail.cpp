// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGrindRail.h"
#include "Net/UnrealNetwork.h"

bool AFortGrindRail::AllowSprinting_Implementation() const
{
	return false;
}

void AFortGrindRail::BPRerunConstructionScript()
{
}

#if WITH_EDITOR
void AFortGrindRail::ConnectSelectedRails()
{
}
#endif

#if WITH_EDITOR
FFortRailPointSnapData AFortGrindRail::GetBestPointToSnapTo(int32 PointToSnap, const TArray<AFortGrindRail*>& SnapAllowedRails)
{
	return FFortRailPointSnapData();
}
#endif

bool AFortGrindRail::GetSpeedSettingsOverride_Implementation(FGrindRailSpeedSettings& SpeedSettingsOverride) const
{
	return false;
}

bool AFortGrindRail::HasHeadConnection() const
{
	return false;
}

bool AFortGrindRail::HasTailConnection() const
{
	return false;
}

bool AFortGrindRail::IsGrindRailEnabled_Implementation() const
{
	return false;
}

void AFortGrindRail::NativeGetNextPositionToGrind(const float DistanceToTravel, const float CurrentDistanceAlongSpline, const float RightLeanValue, FVector& OutNextLocation, bool& bGotToEnd, float& NextLocationOnRail, EGrindRailBoosterMode& BoosterMode, bool& bHitObstacle, bool& bNewRail, float& DistanceAlongNewRail, AFortGrindRail*& TheNewRail, bool& bNewRailReverseDirection)
{
}

void AFortGrindRail::OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags)
{
}

void AFortGrindRail::OnRep_DisableBooster()
{
}

#if WITH_EDITOR
void AFortGrindRail::RemoveConnectionsFromSelectedRails()
{
}
#endif

void AFortGrindRail::SetupMeshInfo(USplineMeshComponent* SplineMeshComponent)
{
}

#if WITH_EDITOR
void AFortGrindRail::SnapPoint(int32 PointIndex, const FFortRailPointSnapData& SnapData)
{
}
#endif

#if WITH_EDITOR
void AFortGrindRail::SplitRail()
{
}
#endif

void AFortGrindRail::UpdateTransientComponentTransforms(TArray<USceneComponent*> TransientSceneComponents)
{
}

void AFortGrindRail::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGrindRail, bDisableBooster);
}
