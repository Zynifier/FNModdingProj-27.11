// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/Systems/AthenaAIService.h"
#include "AthenaAIServiceZoneManager.generated.h"

class AActor;
class UAthenaAIServiceZoneManager;
class UObject;

UENUM()
enum class EAthenaAITrackedZoneType : uint8
{
	Occluder = 0,
	Danger = 1,
};

USTRUCT()
struct FAthenaAITrackedZone
{
	GENERATED_BODY()

};

UCLASS()
class UAthenaAIServiceZoneManager : public UAthenaAIService
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, meta=(WorldContext="WorldContextObject"))
	static UAthenaAIServiceZoneManager* GetAthenaAIServiceZoneManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsInDangerZone(const FVector& Location) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsLOFOccluded(const FVector& StartLocation, const FVector& EndLocation) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterDangerZone(AActor* Actor, const float Radius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterOccluder(AActor* OccluderActor, const float SphereRadius);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterDangerZone(AActor* Actor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterOccluder(AActor* OccluderActor);

private:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OnZoneDestroyed(AActor* Actor);

	UPROPERTY(Transient)
	TArray<FAthenaAITrackedZone> TrackedZones;

};

