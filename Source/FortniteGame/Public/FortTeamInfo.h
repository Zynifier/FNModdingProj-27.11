// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortTeamActorInterface.h"
#include "FortTeamInfo.generated.h"

class AActor;
class AController;
class AFortPlayerController;
class AFortTeamInfo;
class AFortTeamPrivateInfo;
class UPrimitiveComponent;

USTRUCT()
struct FTeamSpottedActorInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(NotReplicated)
	TObjectPtr<AFortPlayerController> Spotter;

	UPROPERTY()
	TObjectPtr<AActor> SpottedActor;

};

USTRUCT()
struct FTeamSpottedActorInfoArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FTeamSpottedActorInfo> SpottedActorInfo;

	UPROPERTY(NotReplicated)
	TObjectPtr<AFortTeamInfo> OwningTeam;

};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortTeamInfo : public AInfo, public IFortTeamActorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Team")
	virtual int32 GetTeamExperience() const;

	UFUNCTION(BlueprintPure, Category="Team")
	virtual int32 GetTeamLevel() const;

	UFUNCTION()
	void OnSpottedActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

protected:
	UPROPERTY()
	TArray<TObjectPtr<AController>> TeamMembers;

	UPROPERTY(Transient, Replicated)
	uint8 Team;

	UPROPERTY(Transient, Replicated)
	FString ChatRoomID;

	UPROPERTY(Replicated)
	FTeamSpottedActorInfoArray TeamSpottedActors;

	UPROPERTY(Replicated)
	TObjectPtr<AFortTeamPrivateInfo> PrivateInfo;

};

